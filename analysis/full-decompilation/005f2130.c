
void __thiscall
FUN_005f2130(int *param_1,undefined4 param_2,int *param_3,int *param_4,int param_5,int *param_6,
            undefined4 param_7,int param_8,int param_9)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = param_1[3] + *param_4 + *param_3;
  local_18 = param_3[1];
  local_8 = param_1[4] + param_4[1] + local_18;
  local_14 = param_3[2];
  local_10 = param_3[3];
  iVar3 = 0;
  local_1c = *param_3 + -1 + param_1[3];
  iVar5 = 0;
  if (param_9 <= param_8) goto LAB_005f21ba;
  iVar1 = *param_1;
  iVar3 = param_8;
  iVar5 = param_9;
  if (param_8 < iVar1) {
    if (iVar1 < param_9) {
      iVar3 = iVar1;
    }
    if (iVar1 <= iVar3) goto LAB_005f2192;
  }
  else {
LAB_005f2192:
    piVar4 = (int *)(param_1[1] + iVar1);
    if (iVar3 < (int)piVar4) {
      param_4 = piVar4;
      piVar2 = (int *)&param_4;
      if (param_9 <= (int)piVar4) {
        piVar2 = &param_9;
      }
      iVar5 = *piVar2;
    }
  }
  if (iVar3 != iVar5) {
    iVar3 = iVar3 - iVar1;
    iVar5 = iVar5 - iVar1;
  }
LAB_005f21ba:
  (**(code **)(*param_6 + 0x78))
            (param_2,local_c,local_8,*param_1 + param_5,param_1[1],&local_1c,iVar3,iVar5);
  return;
}

