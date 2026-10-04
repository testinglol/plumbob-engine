
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00637a41(char *param_1,undefined1 *param_2,undefined2 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined1 local_8c [136];
  
  if (param_1 == (char *)0x0) {
LAB_00637ae7:
    puVar2 = (undefined *)0x0;
  }
  else {
    if ((*param_1 == 'C') && (param_1[1] == '\0')) {
      param_2[1] = 0;
      *param_2 = 0x43;
      if (param_3 != (undefined2 *)0x0) {
        *param_3 = 0;
        param_3[1] = 0;
        param_3[2] = 0;
      }
      if (param_4 == (undefined4 *)0x0) {
        return param_2;
      }
      *param_4 = 0;
      return param_2;
    }
    iVar1 = _strcmp(&DAT_006da9fc,param_1);
    if ((iVar1 != 0) && (iVar1 = _strcmp(&DAT_006da978,param_1), iVar1 != 0)) {
      iVar1 = FUN_00637b7e(local_8c,param_1);
      if ((iVar1 != 0) || (iVar1 = FUN_006435ca(local_8c,&DAT_00703aa4,local_8c), iVar1 == 0))
      goto LAB_00637ae7;
      _DAT_00703aac = (uint)DAT_00703aa8;
      FUN_00637c4a(&DAT_006da9fc,local_8c);
      if (*param_1 == '\0') {
        param_1 = &DAT_006da9fc;
      }
      FUN_006358b0(&DAT_006da978,param_1);
    }
    if (param_3 != (undefined2 *)0x0) {
      FUN_00636510(param_3,&DAT_00703aa4,6);
    }
    if (param_4 != (undefined4 *)0x0) {
      FUN_00636510(param_4,&DAT_00703aac,4);
    }
    FUN_006358b0(param_2,&DAT_006da9fc);
    puVar2 = &DAT_006da9fc;
  }
  return puVar2;
}

