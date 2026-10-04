
void __thiscall FUN_00442db0(int param_1,short param_2,char param_3)

{
  char cVar1;
  int *local_9c;
  int *local_58;
  int local_40;
  int local_1c;
  int *local_10;
  int *local_c;
  int local_8;
  
  local_10 = (int *)FUN_00407498((int)param_2);
  if (local_10 != (int *)0x0) {
    if (*(short *)(local_10[0x46] + 0x14) != 0) {
      local_9c = (int *)FUN_006359f2(local_10,0,&cXObject::RTTI_Type_Descriptor,
                                     &cXMTObject::RTTI_Type_Descriptor,0);
      if (local_9c == (int *)0x0) {
        return;
      }
      cVar1 = FUN_00423481();
      if (cVar1 == '\0') {
        if (local_9c[100] != 0) {
          local_9c = (int *)local_9c[100];
        }
        local_10 = local_9c;
        param_2 = (short)local_9c[0x3c];
      }
    }
    local_c = local_10;
    while (FUN_0043270d(local_c), local_40 != 0) {
      FUN_0043270d(local_c);
      local_c = local_58;
      local_1c = *(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x58) >> 1;
      while (local_1c = local_1c + -1, -1 < local_1c) {
        if (*(short *)(*(int *)(param_1 + 0x58) + local_1c * 2) == (short)local_58[0x3c]) {
          return;
        }
      }
    }
    local_8 = *(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x58) >> 1;
    do {
      local_8 = local_8 + -1;
      if (local_8 < 0) {
        (**(code **)(*local_10 + 0x50))(1);
        local_10[0x45] = local_10[0x45] & 0xffffefff;
        if (param_3 == '\0') {
          local_10[0x45] = local_10[0x45] | 0x1000;
        }
        FUN_004029df(&param_2);
        return;
      }
    } while (*(short *)(*(int *)(param_1 + 0x58) + local_8 * 2) != param_2);
  }
  return;
}

