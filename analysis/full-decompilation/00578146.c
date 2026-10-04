
bool __thiscall FUN_00578146(int *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int local_8;
  
  iVar5 = param_2 * 0x40 + (int)param_3;
  iVar1 = *(int *)(param_1[0xd] + 0x44 + iVar5 * 4);
  if (((((iVar1 != 0) && (*(char *)(param_1[iVar5 + 0x25] + 0x16) == '\0')) &&
       (*(int *)(param_1[iVar5 + 0x25] + 8) == 0)) &&
      (cVar4 = (**(code **)(*param_1 + 0x84))(param_2,param_3), cVar4 != '\0')) &&
     ((param_2 != param_1[0x1f] || (param_3 != (int *)param_1[0x20])))) {
    iVar5 = *(int *)(iVar1 + 0x48);
    if (iVar5 != 0) {
      local_8 = 0;
      iVar7 = *(int *)(param_1[0xd] + 0x24);
      if (0 < iVar7) {
        iVar2 = *(int *)(param_1[0xd] + 0x28);
        param_3 = param_1 + 0x25;
        do {
          param_2 = 0;
          piVar6 = param_3;
          if (0 < iVar2) {
            do {
              iVar3 = *piVar6;
              if (((*(int *)(iVar3 + 0xc) != 0) && (iVar5 == *(int *)(*(int *)(iVar3 + 0xc) + 0x48))
                  ) && ((*(int *)(iVar3 + 8) != 0 && (*(char *)(iVar3 + 0x15) == '\0')))) {
                return false;
              }
              param_2 = param_2 + 1;
              piVar6 = piVar6 + 1;
            } while (param_2 < iVar2);
          }
          local_8 = local_8 + 1;
          param_3 = param_3 + 0x40;
        } while (local_8 < iVar7);
      }
    }
    piVar6 = (int *)**(int **)(iVar1 + 0x50);
    if (piVar6 != *(int **)(iVar1 + 0x50)) {
      do {
        if ((((piVar6[3] < *(int *)(param_1[0xd] + 0x24)) &&
             (piVar6[2] < *(int *)(param_1[0xd] + 0x28))) &&
            (*(int *)(param_1[piVar6[3] * 0x40 + piVar6[2] + 0x25] + 8) != 0)) &&
           (*(char *)(param_1[piVar6[3] * 0x40 + piVar6[2] + 0x25] + 0x15) == '\0')) {
          return false;
        }
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)*(int *)(iVar1 + 0x50));
    }
    if (0x14 < *(int *)(iVar1 + 0x2c)) {
      *(undefined4 *)(iVar1 + 0x2c) = 0x14;
    }
    if (*(int *)(iVar1 + 0x2c) < 0) {
      *(undefined4 *)(iVar1 + 0x2c) = 0;
    }
    if (*(int *)(iVar1 + 0x2c) != 0) {
      if (*(int *)(iVar1 + 0x2c) == 0x14) {
        if ((param_4 != 0) && (iVar5 == param_4)) {
          return (bool)0x65;
        }
        return (bool)100;
      }
      if (param_1[0x15] == 0) {
        param_1[0x15] = 10;
      }
      if ((param_4 != 0) && (*(int *)(iVar1 + 0x48) == param_4)) {
        return (bool)2;
      }
      iVar1 = *(int *)(*(int *)(iVar1 + 0x2c) * 4 + 0x6cf0d0);
      iVar5 = param_1[0x15];
      iVar7 = _rand();
      return iVar7 < iVar1 / iVar5;
    }
  }
  return false;
}

