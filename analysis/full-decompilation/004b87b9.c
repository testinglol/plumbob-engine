
/* WARNING: Type propagation algorithm not settling */

bool FUN_004b87b9(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_EDI;
  bool bVar5;
  undefined1 local_28d0 [4];
  undefined4 local_28cc;
  undefined4 local_28c8;
  undefined4 local_28c4;
  undefined4 local_28c0;
  undefined4 local_28bc;
  undefined4 local_28b8;
  undefined4 local_28b4;
  undefined4 local_24a0;
  undefined4 uStackY_24;
  undefined4 uStackY_20;
  undefined4 *******local_1c;
  
  FUN_00636080();
  if (DAT_006f0664 == '\0') {
    iVar2 = FUN_00582ecc();
    if (iVar2 == 0) {
      return false;
    }
    DAT_006f0664 = '\x01';
  }
  FUN_004b8915();
  iVar2 = FUN_0058316d();
  if (iVar2 == 0) {
    return false;
  }
  iVar2 = FUN_005835a0();
  if (iVar2 != 0) {
    local_1c = (undefined4 *******)0x4b883a;
    _memset(local_28d0,0,0x2890);
    local_28cc = 0x2890;
    local_28c8 = 200;
    local_28c0 = *param_3;
    local_28bc = param_3[1];
    local_28b8 = 0x20;
    local_28b4 = 0x20;
    local_24a0 = param_5;
    local_28c4 = param_6;
    local_1c = (undefined4 *******)&stack0xfffffff0;
    uStackY_20 = 0x4b8893;
    iVar3 = FUN_00583113();
    if (iVar3 != 0) {
      local_1c = &local_1c;
      uStackY_20 = 0x4b88cb;
      uVar1 = unaff_EDI;
      piVar4 = (int *)FUN_00583187();
      uStackY_20 = uVar1;
      local_1c = (undefined4 *******)*piVar4;
      uStackY_24 = 0x4b88ec;
      iVar3 = FUN_00583135();
      bVar5 = iVar3 != 0;
      FUN_00583157();
      goto LAB_004b8901;
    }
  }
  bVar5 = false;
LAB_004b8901:
  if (iVar2 != 0) {
    FUN_005835ac();
  }
  return bVar5;
}

