
void __thiscall FUN_004448e6(int param_1,int param_2)

{
  int *local_c;
  
  if ((param_2 != 0) && (*(short *)(param_2 + 0x626) != 0)) {
    for (local_c = *(int **)(param_1 + 0xb0); local_c != *(int **)(param_1 + 0xb4);
        local_c = local_c + 1) {
      if ((*local_c != 0) && (*(short *)(*local_c + 0xf0) == *(short *)(param_2 + 0xf0))) {
        return;
      }
    }
    FUN_0042eadb(&param_2);
    *(undefined1 *)(param_1 + 0xac) = 1;
  }
  return;
}

