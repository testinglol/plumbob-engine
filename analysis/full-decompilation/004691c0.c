
void __thiscall FUN_004691c0(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = '\x01';
  iVar3 = *(int *)(*param_1 + 4);
  iVar4 = *param_1;
  while (iVar3 != 0) {
    cVar1 = FUN_00469252(iVar3 + 0x10);
    iVar4 = iVar3;
    if (cVar1 == '\0') {
      iVar3 = *(int *)(iVar3 + 0xc);
    }
    else {
      iVar3 = *(int *)(iVar3 + 8);
    }
  }
  if (cVar1 != '\0') {
    if (iVar4 == *(int *)(*param_1 + 8)) goto LAB_0046922a;
    FUN_0042a392();
  }
  cVar1 = FUN_00469252(param_3);
  if (cVar1 == '\0') {
    *(undefined1 *)(param_2 + 1) = 0;
    *param_2 = iVar4;
    return;
  }
LAB_0046922a:
  piVar2 = (int *)FUN_004694a3(&param_3,0,iVar4,param_3);
  *param_2 = *piVar2;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}

