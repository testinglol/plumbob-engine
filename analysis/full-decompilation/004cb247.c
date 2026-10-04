
void __fastcall FUN_004cb247(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x90))(1,0);
    (**(code **)(*param_1 + 0x174))(0,0);
    FUN_005a5e48(0);
  }
  FUN_005dbf4d();
  return;
}

