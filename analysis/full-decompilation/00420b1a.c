
void __thiscall FUN_00420b1a(int param_1,int param_2)

{
  LPCSTR local_10c;
  undefined1 local_104 [256];
  
  FUN_0046f824(local_104,0,0x100);
  FUN_0046f8e4(param_2 + 0x18);
  AppendMenuA(*(HMENU *)(param_1 + 4),0x10,*(UINT_PTR *)(param_2 + 4),local_10c);
  *(int *)(param_2 + 8) = param_1;
  *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + 1;
  return;
}

