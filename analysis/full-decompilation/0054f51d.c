
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0054f51d(int *param_1,char param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  ushort *puVar9;
  int local_8;
  
  if (param_2 == '\0') {
    if ((char)param_1[0x97] != '\0') {
      if ((undefined4 *)param_1[0x36] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)param_1[0x36])(1);
      }
      iVar6 = param_1[0x96];
      param_1[0x96] = 0;
      *(undefined1 *)(param_1 + 0x97) = 0;
      param_1[0x36] = iVar6;
      (**(code **)(*param_1 + 0x168))();
    }
  }
  else if ((char)param_1[0x97] == '\0') {
    param_1[0x96] = param_1[0x36];
    iVar6 = (**(code **)(*(int *)param_1[0x36] + 0x94))();
    param_1[0x36] = iVar6;
    if (iVar6 == 0) {
      iVar6 = param_1[0x96];
      param_1[0x96] = 0;
      param_1[0x36] = iVar6;
    }
    else {
      uVar1 = *(uint *)(iVar6 + 0x24);
      uVar4 = FUN_005dfe3b(param_3,param_4,param_5);
      cVar3 = (**(code **)(*(int *)param_1[0x36] + 0x20))(0x40);
      if (cVar3 != '\0') {
        param_5 = (**(code **)(*(int *)param_1[0x36] + 0xcc))();
        uVar7 = (**(code **)(*(int *)param_1[0x36] + 0xd0))();
        iVar6 = param_1[0x36];
        iVar2 = *(int *)(iVar6 + 0x1c);
        if (*(int *)(DAT_006e486c + 0x34) == 1) {
          local_8 = 0;
          if (0 < *(int *)(iVar6 + 0x20)) {
            do {
              param_4 = 0;
              if (0 < iVar2) {
                puVar9 = (ushort *)(param_5 + -2);
                do {
                  if (puVar9[1] == uVar1) {
                    if ((param_4 < iVar2 + -1) && (puVar9[2] != uVar1)) {
                      puVar9[2] = uVar4;
                    }
                    if ((0 < param_4) && (*puVar9 != uVar1)) {
                      *puVar9 = uVar4;
                    }
                  }
                  else {
                    uVar8 = FUN_00438f76(puVar9[1],0x3f800000,_DAT_006703bc);
                    uVar8 = FUN_0049bd68(uVar8);
                    uVar5 = FUN_0049f1f4(uVar8);
                    puVar9[1] = uVar5;
                  }
                  param_4 = param_4 + 1;
                  puVar9 = puVar9 + 1;
                } while (param_4 < iVar2);
              }
              local_8 = local_8 + 1;
              param_5 = param_5 + (uVar7 >> 1) * 2;
            } while (local_8 < *(int *)(param_1[0x36] + 0x20));
          }
        }
        else {
          local_8 = 0;
          if (0 < *(int *)(iVar6 + 0x20)) {
            do {
              param_4 = 0;
              if (0 < iVar2) {
                puVar9 = (ushort *)(param_5 + -2);
                do {
                  if (puVar9[1] == uVar1) {
                    if ((param_4 < iVar2 + -1) && (puVar9[2] != uVar1)) {
                      puVar9[2] = uVar4;
                    }
                    if ((0 < param_4) && (*puVar9 != uVar1)) {
                      *puVar9 = uVar4;
                    }
                  }
                  else {
                    uVar8 = FUN_00438f9b(puVar9[1],0x3f800000,_DAT_006703bc);
                    uVar8 = FUN_0049bd68(uVar8);
                    uVar5 = FUN_0049f21b(uVar8);
                    puVar9[1] = uVar5;
                  }
                  param_4 = param_4 + 1;
                  puVar9 = puVar9 + 1;
                } while (param_4 < iVar2);
              }
              local_8 = local_8 + 1;
              param_5 = param_5 + (uVar7 >> 1) * 2;
            } while (local_8 < *(int *)(param_1[0x36] + 0x20));
          }
        }
        (**(code **)(*(int *)param_1[0x36] + 0x24))(0x40);
        (**(code **)(*param_1 + 0x168))();
        *(undefined1 *)(param_1 + 0x97) = 1;
      }
    }
  }
  return;
}

