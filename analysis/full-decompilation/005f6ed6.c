
undefined4 __thiscall FUN_005f6ed6(int *param_1,int *param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = (**(code **)(*param_1 + 0x74))(param_3,param_4);
  if (cVar1 == '\0') {
    *param_2 = 0;
    return 0;
  }
  if (param_1[0x35] == 1) {
    iVar2 = (**(code **)(*param_1 + 0x1dc))();
    if (param_3 < iVar2) {
LAB_005f6f52:
      *param_2 = 1;
      return 1;
    }
    if (param_3 < param_1[0x3a]) {
LAB_005f6f67:
      *param_2 = 3;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x1cc))();
    if (iVar3 + param_1[0x3a] <= param_3) {
      iVar2 = (param_1[0x21] - iVar2) - param_1[0x1f];
LAB_005f6f9c:
      *param_2 = ((iVar2 <= param_3) - 1 & 2) + 2;
      return 1;
    }
  }
  else {
    iVar2 = (**(code **)(*param_1 + 0x1e0))();
    if (param_4 < iVar2) goto LAB_005f6f52;
    if (param_4 < param_1[0x3a]) goto LAB_005f6f67;
    iVar3 = (**(code **)(*param_1 + 0x1d0))();
    if (iVar3 + param_1[0x3a] <= param_4) {
      iVar2 = (param_1[0x22] - param_1[0x20]) - iVar2;
      param_3 = param_4;
      goto LAB_005f6f9c;
    }
  }
  *param_2 = 5;
  return 1;
}

