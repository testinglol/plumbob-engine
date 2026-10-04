
void __thiscall FUN_0044387c(int param_1,int param_2)

{
  int local_44;
  int *local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 *local_30;
  int *local_2c;
  char local_28;
  int *local_24;
  int *local_20;
  short local_1c;
  int *local_18;
  undefined1 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_1c = *(short *)(param_2 + 0xf0);
  if (param_2 != 0) {
    if (*(char *)(param_1 + 0x11) != '\0') {
      FUN_00447dc0(param_2);
    }
    if (*(int *)(*(int *)(param_1 + 0x18) + -4 + local_1c * 4) == param_2) {
      *(undefined4 *)(*(int *)(param_1 + 0x18) + -4 + local_1c * 4) = 0;
      local_c = 0;
      local_14 = 0;
      for (local_18 = (int *)(param_1 + 0x30); *local_18 != 0; local_18 = (int *)(*local_18 + 0xe0))
      {
        if (*local_18 == param_2) {
          *local_18 = *(int *)(param_2 + 0xe0);
          local_14 = 1;
          break;
        }
        local_c = *local_18;
      }
      if (param_2 == *(int *)(param_1 + 0x34)) {
        *(int *)(param_1 + 0x34) = local_c;
      }
      local_8 = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,
                             &cXPerson::RTTI_Type_Descriptor,0);
      if (local_8 != 0) {
        for (local_20 = *(int **)(param_1 + 0x84); local_20 != *(int **)(param_1 + 0x88);
            local_20 = local_20 + 1) {
          if (*local_20 == local_8) {
            FUN_004486a3(local_20);
            break;
          }
        }
      }
      local_10 = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,
                              &cXPortal::RTTI_Type_Descriptor,0);
      if (local_10 != 0) {
        for (local_24 = *(int **)(param_1 + 0x90); local_24 != *(int **)(param_1 + 0x94);
            local_24 = local_24 + 1) {
          if (*local_24 == local_10) {
            FUN_004486a3(local_24);
            break;
          }
        }
      }
      do {
        local_28 = '\0';
        for (local_2c = *(int **)(param_1 + 0x38); local_2c != *(int **)(param_1 + 0x3c);
            local_2c = local_2c + 1) {
          if (*local_2c == param_2) {
            FUN_00443c37(param_2);
            local_28 = '\x01';
            break;
          }
        }
      } while (local_28 != '\0');
      for (local_30 = *(undefined4 **)(param_1 + 100); local_30 != *(undefined4 **)(param_1 + 0x68);
          local_30 = local_30 + 1) {
        if (*(int *)*local_30 == param_2) {
          FUN_004370fd();
        }
      }
      local_38 = FUN_0045741b();
      FUN_004497ed(&local_44,&local_38);
      local_34 = local_44;
      if (local_44 != *(int *)(param_1 + 0x70)) {
        local_3c = *(undefined4 **)(local_44 + 0x14);
        for (local_40 = (int *)*local_3c; local_40 != (int *)local_3c[1]; local_40 = local_40 + 1) {
          if (*local_40 == param_2) {
            FUN_004486a3(local_40);
            break;
          }
        }
      }
      *(undefined1 *)(param_1 + 0x44) = 1;
    }
  }
  return;
}

