#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("orig.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    int i = 0;
    char append[50], find[50];
    double orig_sum_a = 0.0, orig_sum_f = 0.0, orig_a, orig_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &orig_a, &orig_f);
        orig_sum_a += orig_a;
        orig_sum_f += orig_f;
    }
    fclose(fp);
    /*for small structure*/
    fp = fopen("opt_ss.txt", "r");
    if (!fp) {
        printf("ERROR opening input file opt.txt\n");
        exit(0);
    }

    double opt_ss_sum_a = 0.0, opt_ss_sum_f = 0.0, opt_ss_a, opt_ss_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &opt_ss_a, &opt_ss_f);
        opt_ss_sum_a += opt_ss_a;
        opt_ss_sum_f += opt_ss_f;
    }
    fclose(fp);
    /*for hash*/
    fp = fopen("opt_h.txt", "r");
    if (!fp) {
        printf("ERROR opening input file opt.txt\n");
        exit(0);
    }

    double opt_h_sum_a = 0.0, opt_h_sum_f = 0.0, opt_h_a, opt_h_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &opt_h_a, &opt_h_f);
        opt_h_sum_a += opt_h_a;
        opt_h_sum_f += opt_h_f;
    }
    fclose(fp);
    fprintf(output, "append() %lf %lf %lf\n",orig_sum_a / 100.0, opt_ss_sum_a / 100.0, opt_h_sum_a / 100.0);
    fprintf(output, "findName() %lf %lf %lf", orig_sum_f / 100.0, opt_ss_sum_f / 100.0, opt_h_sum_f / 100.0);
    fclose(output);
    return 0;
}
