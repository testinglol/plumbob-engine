
void FUN_0057d5c4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = param_2;
  if (param_2 == 0) {
    FUN_005764a8(&param_1);
  }
  else {
    local_8 = 0;
    local_c = param_1;
    iVar2 = FUN_00582244(&local_c);
    *(int *)(iVar2 + 4) = iVar1;
  }
  uVar3 = FUN_0057d622();
  FUN_005805fa(0x7b,uVar3);
  FUN_0057cf17();
  return;
}

