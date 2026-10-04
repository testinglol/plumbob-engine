
undefined4 FUN_0060a094(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uStack00000010;
  uint local_c;
  byte *local_8;
  
  iVar5 = 0;
  local_c = 0;
  local_8 = (byte *)FUN_004096c2();
  uVar1 = FUN_005d49d6();
  uStack00000010 = 0;
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      uVar2 = (uint)*local_8;
      uVar4 = 0;
      if (uVar2 == 0) break;
      if (local_c == 0) {
        iVar3 = FUN_00608ca3(uVar2);
        uVar4 = uVar2;
        if (iVar3 == 0) {
          uVar4 = local_c;
          if (uVar2 == 0x26) {
            if (local_8[1] != 0x26) {
              FUN_00609cb9(param_1,param_2 + iVar5,param_3,0x5f,0,0);
            }
          }
          else if (uVar2 != 10) {
            FUN_00609cb9(param_1,param_2 + iVar5,param_3,uVar2,0,0);
            iVar3 = FUN_00608a15(uVar2);
            iVar5 = iVar5 + iVar3;
          }
        }
      }
      else {
        uVar2 = local_c << 8 | uVar2;
        FUN_00609cb9(param_1,param_2 + iVar5,param_3,uVar2,0,0);
        iVar3 = FUN_00608a15(uVar2);
        iVar5 = iVar5 + iVar3;
        local_c = 0;
        uVar4 = local_c;
      }
      local_c = uVar4;
      uVar4 = uStack00000010 + 1;
      uStack00000010 = uVar4;
      local_8 = local_8 + 1;
    } while (uVar4 < uVar1);
  }
  return CONCAT31((int3)(uVar4 >> 8),1);
}

