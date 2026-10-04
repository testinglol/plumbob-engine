
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005ceef6(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  float local_14 [2];
  int local_c;
  int *local_8;
  
  iVar1 = FUN_005ceecd();
  if (iVar1 == 0) {
    iVar1 = *param_1;
    if (iVar1 != param_1[1]) {
      puVar3 = (undefined4 *)(iVar1 + 0x24);
      do {
        iVar2 = puVar3[-3];
        local_c = iVar1;
        if (iVar2 == 0) {
          iVar2 = FUN_005cfe62(&local_8,0);
LAB_005cef91:
          if (iVar2 != 0) {
            return iVar2;
          }
LAB_005cef99:
          if (local_8 != (int *)0x0) {
            iVar1 = FUN_005d0a0d(iVar1,puVar3 + -6);
            if (((iVar1 != 0) || (iVar1 = FUN_005d0abe(puVar3 + -2,puVar3 + -1,puVar3), iVar1 != 0))
               || (iVar1 = FUN_005d0b17(puVar3 + 1), iVar1 != 0)) {
LAB_005cf061:
              (**(code **)(*local_8 + 4))();
              return iVar1;
            }
            if (puVar3[-3] == 1) {
              local_14[1] = 0.0;
              local_14[0] = DAT_00673438 * (float)puVar3[5] * _DAT_0066742c;
              local_18 = DAT_00673438 * (float)puVar3[2] * _DAT_0066742c;
              iVar1 = FUN_005d0bf3(&local_18,local_14,local_14 + 1);
              if (iVar1 != 0) goto LAB_005cf061;
            }
            FUN_005ceca4(local_8);
            (**(code **)(*local_8 + 4))();
            iVar1 = local_c;
          }
        }
        else {
          if (iVar2 == 1) {
            iVar2 = FUN_005cffec(&local_8,0);
            goto LAB_005cef91;
          }
          if (iVar2 == 2) {
            iVar2 = FUN_005cfd9c(&local_8,0);
            goto LAB_005cef91;
          }
          if (iVar2 != 3) goto LAB_005cef99;
          local_28 = puVar3[-2];
          local_24 = puVar3[-1];
          local_20 = *puVar3;
          local_1c = puVar3[1];
          iVar2 = FUN_005cedcb(&local_28);
          if (iVar2 != 0) {
            return iVar2;
          }
          local_8 = (int *)0x0;
        }
        iVar1 = iVar1 + 0x48;
        puVar3 = puVar3 + 0x12;
      } while (iVar1 != param_1[1]);
    }
    iVar1 = 0;
  }
  return iVar1;
}

