#include<stdio.h>

typedef struct Set Set;
typedef struct Group Group;

struct Set
{
	int vs, count;
	Group *head, *tail;
};

struct Group
{
	int vs;
	Set *set;
	Group *next;
};

void addToSet(Set *s, Group *g)
{
	g->set = s;
	s->vs += g->vs;
	s->count += 1;
	if(s->head==NULL)
	{
		s->head = s->tail = g;
	}
	else
	{
		s->tail->next = g;
		s->tail = s->tail->next;
	}
	return;
}

void makeSet(Group *g1, Group *g2)
{
	Set *set = (Set*) malloc(sizeof(Set));
	set->vs = 0;
	set->count = 0;
	set->head = set->tail = NULL;
	addToSet(set, g1);
	addToSet(set, g2);
	return;
}

void joinSets(Group *g1, Group *g2)
{
	Set *temp = NULL, *set1 = g1->set, *set2 = g2->set;
	if(set1->count < set2->count)
        {
		temp = set1;
		set1 = set2;
		set2 = temp;
	}
	set1->tail->next = set2->head;
	set1->tail = set2->tail;
	set1->vs = set1->vs + set2->vs;
	set1->count = set1->count + set2->count;
	Group *it = set2->head;
	while(it!=NULL)
	{
		it->set = set1;
		it = it->next;
	}
	set2->head = set2->tail = NULL;
	set2->vs = 0;
	free(set2);
	return;
}

void addWire(Group *g1, Group *g2)
{
	if(g1==g2)
		return;
	if(g1->set==g2->set && g1->set!=NULL)
		return;

	if(g1->set==NULL&&g2->set==NULL)
		makeSet(g1, g2);
	else if(g1->set!=NULL&&g2->set==NULL)
		addToSet(g1->set, g2);
	else if(g1->set==NULL&&g2->set!=NULL)
		addToSet(g2->set, g1);
	else if(g1->set!=NULL&&g2->set!=NULL)
		joinSets(g1, g2);
	return;
}

void addVoltage(Group *g)
{
	g->vs += 1;
	if(g->set!=NULL)
	{
		g->set->vs += 1;
	}
	return;
}

void remVoltage(Group *g)
{
	g->vs -= 1;
	if(g->set!=NULL)
	{
		g->set->vs -= 1;
	}
	return;
}



int main()
{
    int n,r,c,temp,x1,x2,y1,y2,i,j,vs1,vs2,val[123]={0}, num[52][52];
    Group **board;
	Set *set1, *set2;
    char type;
    char input[20];
    for(i=65; i<=90; i++)
		val[i] = i-65;
        for(i=97; i<=122; i++)
		val[i] = (i-97)+26;

	for(i=0; i<52; i++)
	{
		for(j=0; j<52; j++)
		{
			num[i][j] = 52*i + j;
		}
	}

    scanf("%d %d %d",&n,&r,&c);
    getchar();
     board = (Group**) malloc(r*sizeof(Group*));
	for(i=0; i<r; i++)
	{
		board[i] = (Group*) malloc(c*sizeof(Group));
		for(j=0; j<c; j++)
		{
			board[i][j].next = NULL;
			board[i][j].set = NULL;
			board[i][j].vs = 0;
		}
	}
    while(n--)
    {
        gets(input);
        type=input[0];
        switch(type)
        {
            case 'W':
                x1 = num[val[input[1]]][val[input[2]]];
                y1 = num[val[input[3]]][val[input[4]]];
				x2 = num[val[input[5]]][val[input[6]]];
				y2 = num[val[input[7]]][val[input[8]]];
				addWire(&board[(y1-1)/5][x1-1],&board[(y2-1)/5][x2-1]);
				break;
			case 'V':
                x1 = num[val[input[1]]][val[input[2]]];
                y1 = num[val[input[3]]][val[input[4]]];
                addVoltage(&board[(y1-1)/5][x1-1]);
                break;
           case 'R':
                x1 = num[val[input[1]]][val[input[2]]];
                y1 = num[val[input[3]]][val[input[4]]];
                remVoltage(&board[(y1-1)/5][x1-1]);
                break;
           case 'L':
                x1 = num[val[input[1]]][val[input[2]]];
                y1 = num[val[input[3]]][val[input[4]]];
				x2 = num[val[input[5]]][val[input[6]]];
				y2 = num[val[input[7]]][val[input[8]]];
				vs1 = board[(y1-1)/5][x1-1].vs;
                vs2 = board[(y2-1)/5][x2-1].vs;
				set1 = board[(y1-1)/5][x1-1].set;
				set2 = board[(y2-1)/5][x2-1].set;
				vs1 = (set1!=NULL)?(set1->vs):(vs1);
                vs2 = (set2!=NULL)?(set2->vs):(vs2);
				if( (vs1==0&&vs2==0) || (vs1>0&&vs2>0) )
                printf("OFF\n");
				else
					printf("ON\n");
				break;
        }

    }
    for(i=0; i<r; i++)
	{
		free(board[i]);
	}
	free(board);
    return 0;
}
