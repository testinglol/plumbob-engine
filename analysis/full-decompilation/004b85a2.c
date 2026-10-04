
void * FUN_004b85a2(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_2c [36];
  void *local_8;
  
  puVar1 = param_2;
  *param_2 = 0;
  *param_3 = 0;
  local_8 = (void *)0x0;
  if (DAT_006f0664 == '\0') {
    iVar2 = FUN_00582ecc();
    if (iVar2 == 0) {
      return (void *)0x0;
    }
    DAT_006f0664 = '\x01';
  }
  FUN_004b8915(local_2c,param_1);
  param_2 = (undefined4 *)FUN_00583594(param_1);
  if (param_2 != (undefined4 *)0x0) {
    iVar2 = FUN_0058316d(local_2c,0);
    if ((iVar2 != 0) && (iVar2 = FUN_00583089(&param_1,param_2,param_1,1), iVar2 != 0)) {
      iVar2 = FUN_005830c1(param_1,0);
      if (iVar2 != 0) {
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = *(undefined4 *)(iVar2 + 0x438);
        }
        local_8 = operator_new(*(int *)(iVar2 + 0x14) * *(int *)(iVar2 + 0x10) * 4);
        if (local_8 != (void *)0x0) {
          *puVar1 = *(undefined4 *)(iVar2 + 0x10);
          *param_3 = *(undefined4 *)(iVar2 + 0x14);
          FUN_005830db(param_1,iVar2,local_8,*(int *)(iVar2 + 0x10) << 2);
        }
        FUN_005a9340(iVar2);
      }
      FUN_005830fd(param_1);
    }
    FUN_005835ac(param_2);
  }
  return local_8;
}

