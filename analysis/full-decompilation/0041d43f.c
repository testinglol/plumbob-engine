
int __thiscall FUN_0041d43f(int param_1,undefined4 *param_2,int param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *local_9c;
  undefined1 local_94 [64];
  undefined4 local_54;
  int local_50;
  ushort local_4a;
  undefined1 local_8 [4];
  
  *(undefined1 *)(param_1 + 0x24) = 1;
  if ((*(int *)(param_1 + 0x20) != 0) &&
     (iVar2 = FUN_0041c6d8(-(uint)(param_1 != 0) & param_1 + 0xcU,0), iVar2 != 0)) {
    return iVar2;
  }
  iVar2 = param_3 + 0x4c;
  if (*(int *)(param_1 + 0x1c) < 1) {
    *param_4 = 0x40;
  }
  else {
    *param_4 = *(int *)(param_1 + 0x1c);
  }
  iVar3 = *param_4;
  do {
    iVar3 = FUN_0041a545(param_2,iVar3);
    if (iVar3 != 0) {
      iVar3 = FUN_00412fc7(local_8);
      if (iVar3 == 0) {
        *(int *)(param_1 + 0x1c) = *param_4;
        param_2[1] = iVar2;
        *param_2 = 0x58585858;
        *(undefined2 *)((int)param_2 + 10) = 4;
        FUN_0046f824(local_94,0,0x40);
        FUN_0046f847(0,0xffffffff);
        _strncpy((char *)(param_2 + 3),local_9c,0x3f);
        *(undefined1 *)((int)param_2 + 0x4b) = 0;
        iVar3 = FUN_0041d5fe(param_2,*param_4);
      }
      return iVar3;
    }
    *(int *)(param_1 + 0x1c) = *param_4;
    if ((*(byte *)((int)param_2 + 10) & 4) != 0) {
      bVar1 = false;
      iVar3 = FUN_0041a545(&local_54,param_2[1] + *param_4);
      if (iVar3 == 0) {
        do {
          if ((local_4a & 4) == 0) break;
          param_2[1] = param_2[1] + local_50;
          bVar1 = true;
          iVar3 = FUN_0041a545(&local_54,param_2[1] + *param_4);
        } while (iVar3 == 0);
        if ((bVar1) && (iVar3 = FUN_0041d5fe(param_2,*param_4), iVar3 != 0)) {
          return iVar3;
        }
      }
      if (param_2[1] == iVar2) {
        iVar3 = *(int *)(param_1 + 0x18);
LAB_0041d578:
        *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) - iVar2;
        return 0;
      }
      if (param_3 + 0x98 <= (int)param_2[1]) {
        local_54 = 0x58585858;
        local_50 = param_2[1] - iVar2;
        local_4a = 4;
        iVar3 = FUN_0041d5fe(&local_54,*param_4 + iVar2);
        if (iVar3 != 0) {
          return iVar3;
        }
        param_2[1] = iVar2;
        iVar3 = FUN_0041d5fe(param_2,*param_4);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = *(int *)(param_1 + 0x18);
        goto LAB_0041d578;
      }
    }
    *param_4 = *param_4 + param_2[1];
    iVar3 = *param_4;
  } while( true );
}

