
void __fastcall FUN_005cad6f(int param_1)

{
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_1c;
  int local_8;
  
  if (*(int *)(param_1 + 0x74) != 0) {
    (**(code **)(*(int *)(param_1 + 0x118) + 4))(0);
    _memset(&local_84,0,0x7c);
    local_78 = *(undefined4 *)(param_1 + 0x48);
    local_7c = *(undefined4 *)(param_1 + 0x4c);
    local_84 = 0x7c;
    local_80 = 7;
    local_1c = 0x4040;
    local_8 = 0;
    (**(code **)(**(int **)(param_1 + 0x74) + 0x18))(*(int **)(param_1 + 0x74),&local_84,&local_8,0)
    ;
    if (local_8 != 0) {
      (**(code **)(*(int *)(param_1 + 0x118) + 4))(local_8);
    }
  }
  return;
}

