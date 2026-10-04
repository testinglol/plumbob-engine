
void __fastcall FUN_0045ef48(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xaf4);
  for (iVar2 = *(int *)(param_1 + 0xaf0); iVar2 != iVar1; iVar2 = iVar2 + 0x9c) {
    *(undefined1 *)(iVar2 + 0x78) = 0;
  }
  return;
}

