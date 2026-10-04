
undefined4 __thiscall FUN_005f2e7f(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((((param_3 == (int *)0x0) || (*param_3 != 0)) && (param_2 != (int *)0x0)) &&
     ((param_3 != (int *)0x0 && (iVar1 = *param_3, iVar1 != 0)))) {
    iVar5 = *param_2;
    iVar4 = iVar5 + iVar1;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    iVar3 = *param_1;
    if (iVar4 < iVar3) {
LAB_005f2ed8:
      iVar5 = iVar5 - iVar3;
      iVar4 = iVar5;
      if (-1 < iVar1) {
        iVar4 = -iVar5;
      }
      *param_3 = iVar1 + iVar4;
      *param_2 = *param_2 - iVar5;
      return 0xffffffff;
    }
    if (iVar4 < param_1[1] + iVar3) {
      *param_2 = iVar4;
    }
    else {
      if (iVar4 < iVar3) goto LAB_005f2ed8;
      iVar2 = param_1[1];
      if (iVar4 == iVar3 + iVar2) {
        iVar3 = (iVar2 - iVar5) + iVar3;
        *param_3 = iVar1 - iVar3;
        *param_2 = *param_2 + iVar3;
        if (((char)param_1[8] != '\0') || (*(char *)((int)param_1 + 0x21) != '\0')) {
          return 1;
        }
      }
      else if (iVar3 + iVar2 < iVar4) {
        iVar3 = (iVar2 - iVar5) + iVar3;
        *param_3 = iVar1 - iVar3;
        *param_2 = *param_2 + iVar3;
        return 1;
      }
    }
  }
  return 0;
}

