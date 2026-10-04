
void __fastcall FUN_00525baf(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x174))(1,0);
    (**(code **)(*param_1 + 0x90))(4,0);
    uVar2 = FUN_005e74ca(3);
    FUN_005dde6d(uVar2);
  }
  FUN_005dbf32();
  return;
}

