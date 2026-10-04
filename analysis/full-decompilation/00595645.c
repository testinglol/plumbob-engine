
void __thiscall
FUN_00595645(int *param_1,int param_2,int *param_3,undefined4 param_4,undefined4 param_5,
            uint param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_c;
  int local_8;
  
  piVar2 = param_3;
  *param_1 = param_2;
  param_1[1] = (int)param_3;
  param_3 = (int *)0x0;
  *piVar2 = *piVar2 + 1;
  iVar4 = *(int *)(param_1[1] + 0x20) - *(int *)(param_1[1] + 0x1c) >> 2;
  if (0 < iVar4) {
    do {
      iVar1 = *(int *)(*(int *)(param_1[1] + 0x1c) + (int)param_3 * 4);
      if ((param_6 == 0xffffffff) || ((*(uint *)(iVar1 + 0x20) & param_6) != 0)) {
        iVar3 = *param_1;
        if (*(uint *)(iVar1 + 0xc) < (uint)(*(int *)(iVar3 + 0x74) - *(int *)(iVar3 + 0x70) >> 2)) {
          param_2 = *(int *)(*(int *)(iVar3 + 0x70) + *(uint *)(iVar1 + 0xc) * 4);
        }
        else {
          param_2 = 0;
        }
        if (((param_2 != 0) && (DAT_006f75e8 != (code *)0x0)) &&
           (iVar3 = (*DAT_006f75e8)(iVar3,param_1[1],param_2,iVar1,param_4), iVar3 != 0)) {
          local_10 = param_2;
          local_c = iVar1;
          local_8 = iVar3;
          FUN_0059b0ca(&local_10);
          *(undefined4 *)(*param_1 + 0x98) = 1;
          *(int *)(*param_1 + 0xac) = *(int *)(*param_1 + 0xac) + 1;
        }
      }
      param_3 = (int *)((int)param_3 + 1);
    } while ((int)param_3 < iVar4);
  }
  return;
}

