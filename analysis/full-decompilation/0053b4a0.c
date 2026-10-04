
void __thiscall FUN_0053b4a0(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  
  if (param_1[0x68] == param_2) {
    return;
  }
  param_1[0x68] = param_2;
  piVar1 = *(int **)(DAT_006f2a08 + 0x88);
  if (piVar1 == (int *)0x0) {
    return;
  }
  FUN_004e609e();
  cVar2 = FUN_004e6133();
  if (cVar2 == '\0') {
    iVar3 = *(int *)(*(int *)(DAT_006e486c + 0x3c) + 0x20) -
            *(int *)(*(int *)(DAT_006e486c + 0x3c) + 0x18);
    if (param_1[0x68] == 0) {
      (**(code **)(*piVar1 + 0x94))();
      iVar3 = (piVar1[0x20] - piVar1[0x22]) + 0x32 + iVar3;
    }
    else {
      (**(code **)(*piVar1 + 0x98))();
    }
  }
  else {
    if (param_1[0x68] == 0) {
      (**(code **)(*piVar1 + 0xa8))(1);
      goto LAB_0053b56d;
    }
    (**(code **)(*piVar1 + 0xa8))(0,0,0);
    FUN_005ddfdc(1);
    iVar3 = *(int *)(*(int *)(DAT_006e486c + 0x3c) + 0x20) -
            *(int *)(*(int *)(DAT_006e486c + 0x3c) + 0x18);
  }
  FUN_004b157a(iVar3);
LAB_0053b56d:
  iVar3 = (**(code **)(*param_1 + 0x18))();
  if ((iVar3 != 0) && (param_1[0x4b] != 0)) {
    iVar3 = (**(code **)(*param_1 + 0x18))();
    FUN_004cb21d(0,((*(int *)(param_1[0x4b] + 0x18) - *(int *)(param_1[0x4b] + 0x20)) -
                   *(int *)(iVar3 + 0x80)) + *(int *)(iVar3 + 0x88));
  }
  (**(code **)(*param_1 + 0x168))();
  return;
}

