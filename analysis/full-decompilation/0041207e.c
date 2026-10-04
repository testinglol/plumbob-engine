
void FUN_0041207e(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = param_1;
  iVar2 = (**(code **)*param_1)();
  iVar2 = iVar2 + -1;
  iVar5 = -1;
  if (-1 < iVar2) {
    do {
      iVar5 = iVar2;
      if ((*(char *)(param_1[1] + iVar2) == '\\') || (*(char *)(param_1[1] + iVar2) == '/')) break;
      iVar2 = iVar2 + -1;
      iVar5 = -1;
    } while (-1 < iVar2);
  }
  iVar3 = (**(code **)*param_1)();
  iVar4 = iVar3 + -1;
  iVar2 = iVar3;
  if (iVar5 < iVar4) {
    do {
      iVar2 = iVar4;
      if (*(char *)(param_1[1] + iVar4) == '.') break;
      iVar4 = iVar4 + -1;
      iVar2 = iVar3;
    } while (iVar5 < iVar4);
  }
  param_1 = (undefined4 *)iVar2;
  *(undefined2 *)(param_2 + 8) = 0;
  **(undefined1 **)(param_2 + 4) = 0;
  FUN_0046f917(puVar1,iVar5 + 1);
  *(undefined2 *)(param_3 + 8) = 0;
  **(undefined1 **)(param_3 + 4) = 0;
  FUN_0046f847(puVar1[1] + 1 + iVar5,((int)param_1 - iVar5) + -1);
  *(undefined2 *)(param_4 + 8) = 0;
  **(undefined1 **)(param_4 + 4) = 0;
  FUN_0046f847(puVar1[1] + (int)param_1,0xffffffff);
  return;
}

