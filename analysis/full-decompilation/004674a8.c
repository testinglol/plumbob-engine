
void __fastcall FUN_004674a8(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = 6;
  local_c = param_1;
  local_8 = param_1;
  do {
    iVar1 = FUN_005cff27(&local_8,0);
    if (iVar1 == 0) {
      puVar2 = &local_8;
    }
    else {
      local_c = 0;
      puVar2 = &local_c;
    }
    FUN_00468a79(puVar2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

