{
    {{#OPERAND}}
    {{TYPE}} *a{{NR}}_current = a{{NR}}_first{{#ARRAY}} + a{{NR}}_start{{/ARRAY}};
    {{/OPERAND}}

    {{TYPE_AXIS}} axis = *a{{NR_SINPUT}}_first;
    {{TYPE_INPUT}} rvar = 0;

    int64_t nelements   = a{{NR_FINPUT}}_shape[axis];
    int mthreads        = omp_get_max_threads();
    int64_t nworkers    = nelements > mthreads ? mthreads : 1;

    #pragma omp parallel for reduction(+:rvar) num_threads(nworkers)
    for(int64_t j=0; j<a{{NR_FINPUT}}_shape[axis]; ++j) {
        {{TYPE_INPUT}} *tmp_current = a{{NR_FINPUT}}_current + a{{NR_FINPUT}}_stride[axis]*j;

        {{#OPERATORS}}
        {{OPERATOR}};
        {{/OPERATORS}}
    }
    *a{{NR_OUTPUT}}_current = rvar;
}

