
void __thiscall FUN_00444346(int param_1,int param_2)

{
  int *local_8;
  
  for (local_8 = *(int **)(param_1 + 0x84); local_8 != *(int **)(param_1 + 0x88);
      local_8 = local_8 + 1) {
    if (*local_8 != param_2) {
      (**(code **)(*(int *)*local_8 + 0x38))(param_2);
    }
  }
  return;
}

