
bool FUN_004e2b07(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  iVar1 = FUN_00425ddf(param_1);
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x10c);
  }
  iVar1 = FUN_004273c8(param_1,param_2);
  if (iVar1 == 0) {
    FUN_004e19b2(uVar2,1);
  }
  return iVar1 == 0;
}

