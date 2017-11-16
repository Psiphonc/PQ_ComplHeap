#pragma once
#define Parent(x) ((x-1)>>1)
#define LChild(x) (((x)<<1)+1)
#define RChild(x) ((x+1)<<1)
#define InHeap(n,x) ((-1)<(x)&&(x)<(n))
#define ParentValid(x) (0<(x))
#define LChildValid(n,x) (InHeap(n,LChild(x)))
#define RChildValid(n,x) (InHeap(n,RChild(x)))
#define Bigger(PQ,x,y) (((PQ[x])<(PQ[y]))?(y):(x))
#define ProperParent(PQ,n,x)							\
(														\
	RChildValid(n,x)?									\
		Bigger(PQ,(x),Bigger(PQ,LChild(x),RChild(x))):	\
		(												\
			LChildValid(n,x)?							\
				Bigger(PQ,x,LChild(x)):					\
				(x)										\
		)												\
)
#define LastInternal(n) (Parent(n-1))