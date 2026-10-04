
void __thiscall FUN_0040da9a(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int local_158;
  int local_c0;
  char *local_28;
  undefined1 local_20 [4];
  undefined **local_1c;
  char *local_18;
  undefined2 local_14;
  undefined1 local_10 [4];
  int local_c;
  int local_8;
  
  local_c = FUN_0040d879();
  iVar1 = FUN_0040d8a9();
  local_8 = iVar1;
  FUN_00472f33(iVar1 * 0x98 + **(int **)(param_1 + 0x84));
  FUN_0046f824(local_20,0,4);
  FUN_0046f847(local_158 + 6,3);
  FUN_0040d302();
  FUN_0046f824(local_10,0,4);
  local_1c = &PTR_FUN_0066663c;
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 == local_8) {
      return;
    }
    if (iVar1 < 0) {
      iVar1 = local_c + -1;
    }
    local_14 = 0;
    *local_18 = '\0';
    FUN_00473077(iVar1 * 0x98 + **(int **)(param_1 + 0x84));
    FUN_0046f847(local_c0 + 6,3);
    iVar2 = _strcmp(local_18,local_28);
  } while (iVar2 != 0);
  FUN_0040d913(iVar1,param_2);
  return;
}

