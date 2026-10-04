
bool FUN_004b8690(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined1 local_28c0 [4];
  undefined4 local_28bc;
  undefined4 local_28b8;
  undefined4 local_28b4;
  undefined4 local_28b0;
  undefined4 local_28ac;
  undefined4 local_28a8;
  undefined4 local_28a4;
  undefined4 local_2490;
  undefined4 uStackY_20;
  undefined1 *puStackY_1c;
  
  FUN_00636080();
  if (DAT_006f0664 == '\0') {
    iVar1 = FUN_00582ecc();
    if (iVar1 == 0) {
      return false;
    }
    DAT_006f0664 = '\x01';
  }
  FUN_004b8915();
  iVar1 = FUN_0058316d();
  if (iVar1 == 0) {
    return false;
  }
  iVar1 = FUN_005835a0();
  if (iVar1 != 0) {
    puStackY_1c = (undefined1 *)0x4b870f;
    _memset(local_28c0,0,0x2890);
    local_28bc = 0x2890;
    local_28b8 = 200;
    local_28b0 = *param_3;
    local_28ac = param_3[1];
    local_28a8 = 0x20;
    local_28a4 = 0x20;
    local_2490 = param_4;
    local_28b4 = param_5;
    puStackY_1c = &stack0xfffffff4;
    uStackY_20 = 0x4b876a;
    iVar2 = FUN_00583113();
    if (iVar2 != 0) {
      puStackY_1c = (undefined1 *)0x0;
      uStackY_20 = 0x4b8794;
      iVar2 = FUN_00583135();
      bVar3 = iVar2 != 0;
      FUN_00583157();
      goto LAB_004b87a8;
    }
  }
  bVar3 = false;
LAB_004b87a8:
  if (iVar1 != 0) {
    FUN_005835ac();
  }
  return bVar3;
}

