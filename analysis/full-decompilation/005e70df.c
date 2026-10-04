
void __thiscall FUN_005e70df(int *param_1,int *param_2,int param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if ((param_4 == *param_1) || (param_3 != 0)) {
LAB_005e7121:
    iVar2 = FUN_005e7244(param_5);
    *(int *)(param_4 + 8) = iVar2;
    iVar3 = *param_1;
    if (param_4 != iVar3) {
      if (param_4 == *(int *)(iVar3 + 8)) {
        *(int *)(iVar3 + 8) = iVar2;
      }
      goto LAB_005e7145;
    }
    *(int *)(iVar3 + 4) = iVar2;
    iVar3 = *param_1;
  }
  else {
    cVar1 = FUN_00430155(param_5,param_4 + 0x10);
    if (cVar1 != '\0') goto LAB_005e7121;
    iVar2 = FUN_005e7244(param_5);
    *(int *)(param_4 + 0xc) = iVar2;
    iVar3 = *param_1;
    if (param_4 != *(int *)(iVar3 + 0xc)) goto LAB_005e7145;
  }
  *(int *)(iVar3 + 0xc) = iVar2;
LAB_005e7145:
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(int *)(iVar2 + 4) = param_4;
  FUN_00430367(iVar2,*param_1 + 4);
  param_1[1] = param_1[1] + 1;
  *param_2 = iVar2;
  return;
}

