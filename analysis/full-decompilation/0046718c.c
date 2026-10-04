
void __thiscall FUN_0046718c(int param_1,int param_2)

{
  undefined1 local_10 [8];
  int local_8;
  
  if (param_2 == 0) {
    FUN_00468cce();
  }
  else {
    FUN_00468cce();
    local_8 = *(int *)(*(int *)(param_1 + 0x10) + 8);
    if (local_8 != *(int *)(param_1 + 0x10)) {
      do {
        if (*(char *)(local_8 + 0x12) != param_2) {
          FUN_004691c0(local_10,local_8 + 0x10);
        }
        FUN_0041674f();
      } while (local_8 != *(int *)(param_1 + 0x10));
    }
    FUN_00468ca3((int *)(param_1 + 0x10));
  }
  return;
}

