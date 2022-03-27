#include<stdio.h>
#include<math.h>

/* 
1. expr → expr + term {print(1)}
2. expr → expr – term {print(2)}
3. expr → term {print(3)}
4. term → term * factor {print(4)}
5. term → term / factor {print(5)}
6. term → factor {print(6)}
7. factor → ( expr ) {print(7)}
8. factor → 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
*/

/* 
1. 문자열 배열을 인풋받으면
2. 숫자는 8번 규칙에 의해 factor로
3. 기호는 판별 후
4. * 또는 / 일 경우 4번 또는 5번 규칙을 적용한다
5. 그리고 왼쪽 항은 term, 오른쪽 항은 factor을 적용한다.
6. + 또는 - 일 경우 1번 또는 2번 규칙을 적용한다.
7. 그리고 왼쪽항은 expr 오른쪽 항은 term으로 적용한다.
*/


void match(char token);
char nexttoken();

char lookahead;

void main() {
	lookahead = nexttoken();
	exp();
	if (lookahead == ‘$’)
		printf("\n");
	else
		printf(" error\n");
}

void match(char token) {
	if (lookahead == token)
		lookahead = nexttoken();
	else {
		printf(" error\n");
		exit(1);
	}
}

char nexttoken() {
	char c;
	while (1) {
		c = getchar();
		if (c == ' ' || c == '\t' || c == '\n' || c == '\0') continue;
		return(c);
	}
}