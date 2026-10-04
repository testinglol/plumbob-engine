
undefined4 FUN_0059181d(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined1 local_10 [12];
  
  cVar1 = FUN_005928fd(param_2,local_10);
  if (cVar1 != '\0') {
    iVar2 = FUN_004b46a0();
    if (iVar2 != 0) {
      FUN_00462be8(local_10);
      FUN_004b469d();
      FUN_004b9843();
      return 1;
    }
  }
  return 0;
}

