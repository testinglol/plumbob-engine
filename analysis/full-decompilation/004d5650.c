
void __fastcall FUN_004d5650(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x90))(1,0);
  }
  FUN_005dbf4d();
  return;
}

