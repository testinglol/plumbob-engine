
undefined4 * __cdecl FUN_6001a797(int param_1,int param_2)

{
  int *piVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar11;
  undefined4 *puVar12;
  int local_4c;
  char local_48;
  int local_40;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  piVar1 = *(int **)(param_1 + 0x14);
  iVar4 = FUN_6001abec((int)piVar1,param_2);
  iVar5 = FUN_60019f9c(*piVar1);
  if (iVar4 < iVar5) {
    uVar6 = FUN_6001aac4();
    uVar7 = FUN_6001aae4();
    uVar8 = FUN_6001ac52(piVar1,iVar4);
    uVar9 = FUN_6001ac85(piVar1,iVar4);
    uVar10 = FUN_6001acfc(piVar1,iVar4);
    iVar5 = FUN_600011b3((byte *)(*piVar1 + 9),1);
    uVar2 = FUN_6001acb8((int)piVar1,iVar4);
    uVar3 = FUN_6001acda((int)piVar1,iVar4);
    local_4c = FUN_6001ab01((int)piVar1);
    local_8 = (undefined4 *)FUN_600021ef(0x2890);
    if (local_8 != (undefined4 *)0x0) {
      puVar12 = local_8;
      for (iVar11 = 0xa24; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
      *local_8 = 0x464e5449;
      local_8[1] = 0x2890;
      local_8[2] = 0xb4;
      local_8[3] = iVar4;
      local_8[4] = uVar8;
      local_8[5] = uVar9;
      local_8[0x10a] = 0;
      local_8[0x10b] = 0;
      local_8[0x10c] = 100;
      local_8[0x10e] = uVar7;
      local_8[0x10f] = uVar6;
      local_8[0x110] = uVar6;
      local_8[0x111] = uVar6;
      local_8[0x112] = -CONCAT31(extraout_var,uVar2);
      local_8[0x113] = -CONCAT31(extraout_var_00,uVar3);
      local_8[0x114] = 0;
      local_8[0x115] = 0;
      local_8[0x116] = 2;
      local_8[6] = 8;
      local_8[7] = local_4c;
      if (local_4c < 2) {
        local_4c = 2;
      }
      else {
        local_4c = local_4c * local_4c;
      }
      for (local_40 = 0; local_40 < local_4c; local_40 = local_40 + 1) {
        *(char *)((int)local_8 + local_40 * 4 + 0x2b) = (char)((local_40 * 0xff) / (local_4c + -1));
        *(char *)((int)local_8 + local_40 * 4 + 0x2a) = (char)((local_40 * 0xff) / (local_4c + -1));
        *(char *)((int)local_8 + local_40 * 4 + 0x29) = (char)((local_40 * 0xff) / (local_4c + -1));
        *(char *)(local_8 + local_40 + 10) = (char)((local_40 * 0xff) / (local_4c + -1));
      }
      local_8[9] = local_4c;
      local_8[8] = 0;
      iVar11 = FUN_600011b3((byte *)(*piVar1 + 4),1);
      local_48 = (char)iVar4 + (char)iVar11;
      *(undefined1 *)(local_8 + 0x117) = 99;
      *(undefined1 *)((int)local_8 + 0x45d) = 0x68;
      *(undefined1 *)((int)local_8 + 0x45e) = 0x72;
      *(char *)((int)local_8 + 0x45f) = local_48;
      local_8[0x21f] = uVar10;
      local_8[0x220] = -CONCAT31(extraout_var_00,uVar3);
      local_8[0x221] = -CONCAT31(extraout_var,uVar2);
      local_8[0x222] = iVar5;
    }
  }
  return local_8;
}

