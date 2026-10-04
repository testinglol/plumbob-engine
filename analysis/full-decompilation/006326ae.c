
int * __thiscall FUN_006326ae(int *param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_14 [16];
  
  iVar2 = FUN_006327fb(0);
  if (iVar2 != 0) {
    uVar3 = FUN_0063411f(local_14);
    iVar2 = FUN_00638e1e(local_14,0,uVar3);
    iVar4 = 0x7fffffff;
    if ((iVar2 <= 0x7fffffff) && (iVar4 = -0x80000000, -0x80000000 <= iVar2)) {
      *param_2 = iVar2;
    }
    else {
      *param_2 = iVar4;
      puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
      *puVar1 = *puVar1 | 2;
    }
    FUN_00632716();
  }
  return param_1;
}

