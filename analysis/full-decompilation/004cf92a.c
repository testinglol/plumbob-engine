
void __thiscall FUN_004cf92a(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xd4) != param_2) {
    *(undefined4 *)(param_1 + 0xec + (*(int *)(param_1 + 0xd4) + *(int *)(param_1 + 0xd0) * 8) * 4)
         = *(undefined4 *)(param_1 + 0xe0);
    *(int *)(param_1 + 0xd4) = param_2;
    FUN_004cf579();
    FUN_004cf136(7,0xffffffff);
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 4;
  }
  return;
}

