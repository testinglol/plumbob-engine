
void __thiscall FUN_004650d0(undefined4 *param_1,int param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  iVar1 = param_2;
  for (piVar2 = (int *)*param_1;
      (piVar2 != (int *)param_1[1] && (*(int *)(*piVar2 + 0xc) != param_2)); piVar2 = piVar2 + 1) {
  }
  if (piVar2 == (int *)param_1[1]) {
    FUN_00465150(param_2);
    for (piVar2 = (int *)*param_1; piVar2 != (int *)param_1[1]; piVar2 = piVar2 + 1) {
      if (*(int *)(*piVar2 + 0xc) == iVar1) {
        if (piVar2 == (int *)param_1[1]) {
          return;
        }
        goto LAB_00465116;
      }
    }
  }
  else {
LAB_00465116:
    iVar1 = ((int *)*piVar2)[1];
    uVar3 = iVar1 - *(int *)*piVar2 >> 2;
    if (uVar3 < param_3) {
      param_2 = 0;
      FUN_0046534a(iVar1,param_3 - uVar3,&param_2);
    }
    else if (param_3 < uVar3) {
      FUN_0052ea87(iVar1 + (param_3 - uVar3) * 4,iVar1);
    }
  }
  return;
}

