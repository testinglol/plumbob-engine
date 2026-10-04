
int __thiscall FUN_00418073(int param_1,undefined4 *param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_14;
  int local_10;
  ushort local_a;
  
  piVar2 = param_4;
  puVar1 = param_2;
  param_3 = param_3 + 0x10;
  if (*(int *)(param_1 + 0x2c) < 1) {
    *param_4 = 0x40;
  }
  else {
    *param_4 = *(int *)(param_1 + 0x2c);
  }
  iVar3 = *param_4;
  do {
    iVar3 = FUN_004181b3(puVar1,iVar3);
    if (iVar3 != 0) {
      iVar3 = FUN_00412fc7(&param_2);
      if (iVar3 == 0) {
        *(int *)(param_1 + 0x2c) = *piVar2;
        *puVar1 = 0x58585858;
        puVar1[1] = param_3;
        *(undefined2 *)((int)puVar1 + 10) = 4;
        iVar3 = FUN_00418223(puVar1,*piVar2);
      }
      return iVar3;
    }
    *(int *)(param_1 + 0x2c) = *piVar2;
    if ((*(byte *)((int)puVar1 + 10) & 4) != 0) {
      param_4 = (int *)0x0;
      iVar3 = FUN_004181b3(&local_14,puVar1[1] + *piVar2);
      if (iVar3 == 0) {
        do {
          if ((local_a & 4) == 0) break;
          param_4 = (int *)0x1;
          puVar1[1] = puVar1[1] + local_10;
          iVar3 = FUN_004181b3(&local_14,*piVar2 + puVar1[1]);
        } while (iVar3 == 0);
        if (((short)param_4 != 0) && (iVar3 = FUN_00418223(puVar1,*piVar2), iVar3 != 0)) {
          return iVar3;
        }
      }
      if (puVar1[1] == param_3) {
LAB_00418174:
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - param_3;
        return 0;
      }
      if (param_3 + 0x10 <= (int)puVar1[1]) {
        local_14 = 0x58585858;
        local_10 = puVar1[1] - param_3;
        local_a = 4;
        iVar3 = FUN_00418223(&local_14,*piVar2 + param_3);
        if (iVar3 != 0) {
          return iVar3;
        }
        puVar1[1] = param_3;
        iVar3 = FUN_00418223(puVar1,*piVar2);
        if (iVar3 != 0) {
          return iVar3;
        }
        goto LAB_00418174;
      }
    }
    *piVar2 = *piVar2 + puVar1[1];
    iVar3 = *piVar2;
  } while( true );
}

