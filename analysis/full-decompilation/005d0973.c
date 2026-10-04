
void __fastcall FUN_005d0973(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = (int *)FUN_005d012d();
  iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,param_1 + 0xc,0);
  if (iVar2 == 0) {
    local_8 = 0x3f800000;
    local_c = 0x3f800000;
    local_10 = 0x3f800000;
    iVar2 = FUN_005d0abe(&local_10,&local_c,&local_8);
    if (iVar2 == 0) {
      local_10 = 0x3f800000;
      FUN_005d0b17(&local_10);
    }
  }
  return;
}

