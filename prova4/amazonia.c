#include <stdio.h>
#include <stdlib.h>

#define Item int
#define loop(N) for(Item i = 0; i < N; i++)
#define exch(A, B) { Item t = A; A = B; B = t; }
#define all "All stations are reachable.\n"
#define notAll "There are stations that are unreachable.\n"

Item N;
Item pre[1010];
Item X[1010];
Item Y[1010];
Item G[1000][2];

Item near(Item a, Item b) {
    if (X[a] < X[b])
        return 1;
    else if (X[a] == X[b])
        return Y[a] < Y[b];
    else
        return 0;
}

void order_station(Item a, Item b, Item distance0, Item distance1) {
    if (distance1 < distance0 || (distance1 == distance0 && near(b, a))) {
        exch(distance0, distance1);
        exch(a, b);
    }
}

void distance() {
    loop(N) {
        G[i][0] = -1;
        G[i][1] = -1;
        Item distance0 = 0;
        Item distance1 = 0;

        for (Item j = 0; j < N; j++)
        if (j != i) {
            Item dx = X[i] - X[j];
            Item dy = Y[i] - Y[j];
            Item distance = dx * dx + dy * dy;

            if (G[i][0] == -1) {
                G[i][0] = j;
                distance0 = distance;
                continue;
            } else if (G[i][1] == -1) {
                G[i][1] = j;
                distance1 = distance;
            } else {
                if (distance == distance1){
                    if (near(j, G[i][1]))
                        G[i][1] = j;
                } else if (distance1 > distance) {
                    G[i][1] = j;
                    distance1 = distance;
                }
            }

            order_station(G[i][0], G[i][1], distance0, distance1);
        }
    }
}

void dfsR(Item v) {
  pre[v] = 1;

  for (Item i = 0; i < 2; i++)
        if (pre[G[v][i]] == 0)
            dfsR(G[v][i]);
}

void clean_pre() {
    loop(N) {
        pre[i] = 0;
    }
}

Item check_all_stations() {
    loop(N) {
        if (!pre[i]) {
            return 0;
        }
    }

    return 1;
}

Item resolve_and_check_all_stations() {
    distance();

    clean_pre();
    
    dfsR(N);

    return check_all_stations();
}

Item main() {
    while (scanf("%d\n", &N) != EOF && N != 0) {
        loop(N) {
            scanf("%d %d\n", &X[i], &Y[i]);
        }

        printf("%s", resolve_and_check_all_stations() ? all : notAll);
    }
    
    return 0;
}