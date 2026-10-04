
void __fastcall FUN_004b91b0(int param_1)

{
  if (*(HGDIOBJ *)(param_1 + 4) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  if (*(int *)(param_1 + 8) != 0) {
    FUN_006321f0(*(int *)(param_1 + 8));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

