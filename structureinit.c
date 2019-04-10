#include<stdlib.h>
#include<sys/types.h>
#include<stdio.h>
#include<math.h>
#include<unistd.h>
#include<pthread.h>
struct station 
{
int external_passengers;//waiting passengers
int internal_passengers;//in train passengers
int boarded_passengers;//boarded passengers
pthread_mutex_t lock;
pthread_cond_t passengers_seated_cond;
};
void station_init (struct station *s);
void station_load_train(struct station *s,int count);
void *station_wait_for_train(struct station *s);
void station_on_board(struct station *s);
void *thread_passenger(void *args);//passenger function
void *train_thread(void *args);// train loading function
//initializing the waiting passengers,in train passengers,boareded passengers,lock,condition statements;
void station_init(struct station *s)
{
s->external_passengers = 0;
s->boarded_passengers =0;
s->internal_passengers =0;
pthread_mutex_init(&(s->lock),NULL);
pthread_cond_init(&(s->passengers_seated_cond),NULL);
}
