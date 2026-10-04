
int __thiscall FUN_00473790(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined **local_64 [3];
  undefined1 local_58 [64];
  undefined2 *local_18;
  int local_14;
  ushort *local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar2 = (ushort *)0x0;
  FUN_0046f824(local_58,0,0x40);
  local_64[0] = &PTR_FUN_0066651c;
  local_14 = FUN_00473ab8(param_1,param_2,0x5452434e,param_3,0);
  if (local_14 == 0) {
    local_c = (**(code **)(*param_2 + 0x38))(0x42434f4e,param_3,FUN_00402024);
    local_14 = FUN_00401f6f();
    if (local_14 == 0) {
      (**(code **)(*param_2 + 0x48))(local_c,local_64);
      local_18 = (undefined2 *)FUN_00420048(local_c);
      *(byte *)(param_1 + 0x1b) = (byte)((ushort)*local_18 >> 0xf);
      local_10 = (ushort *)0x0;
      iVar1 = FUN_006359f2(param_2,0,&iResFile::RTTI_Type_Descriptor,
                           &ObjResFile::RTTI_Type_Descriptor,0);
      if (iVar1 != 0) {
        puVar2 = (ushort *)FUN_0045697c(param_3);
        local_10 = puVar2;
      }
      local_8 = 0;
      if ((int)(param_1[3] - param_1[2]) / 0x30 != 0) {
        iVar1 = 0;
        local_18 = (undefined2 *)((int)local_18 - (int)puVar2);
        puVar3 = puVar2;
        do {
          puVar2 = puVar2 + 1;
          *(uint *)(param_1[2] + iVar1) = local_8;
          *(undefined2 *)(param_1[2] + 0x16 + iVar1) = *(undefined2 *)((int)local_18 + (int)puVar2);
          *(undefined2 *)(param_1[2] + 0xe + iVar1) = 0;
          *(undefined1 *)(param_1[2] + 0xc + iVar1) = 0;
          if ((puVar3 != (ushort *)0x0) && ((int)local_8 < (int)(*puVar3 & 0x7fff))) {
            *(ushort *)(param_1[2] + 0xe + iVar1) = *puVar2;
            *(undefined1 *)(param_1[2] + 0xc + iVar1) = 1;
          }
          local_8 = local_8 + 1;
          iVar1 = iVar1 + 0x30;
          puVar3 = local_10;
        } while (local_8 < (uint)((int)(param_1[3] - param_1[2]) / 0x30));
      }
      FUN_0042004f(local_c);
      *(undefined2 *)(param_1 + 1) = (undefined2)param_3;
      *param_1 = param_2;
      FUN_0046f8e4(local_64);
      goto LAB_00473909;
    }
  }
  FUN_00473a46(param_1[2],param_1[3]);
LAB_00473909:
  FUN_0052ea87(param_1[5],param_1[6]);
  return local_14;
}

