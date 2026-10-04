
void __fastcall FUN_00584d6e(int *param_1)

{
  int iVar1;
  
  *(undefined1 *)((int)param_1 + 0xd9) = 1;
  (**(code **)(*param_1 + 0x10))();
  iVar1 = FUN_00458058(0);
  param_1[0x37] = iVar1;
  (**(code **)(*param_1 + 0xd4))(0);
  (**(code **)(*param_1 + 0x18))();
  param_1[0x27] = -1;
  *(undefined1 *)((int)param_1 + 0xd9) = 1;
  return;
}

