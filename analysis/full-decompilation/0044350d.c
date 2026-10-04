
/* WARNING: Type propagation algorithm not settling */

uint __thiscall FUN_0044350d(int param_1,int param_2,short param_3,char param_4)

{
  short sVar1;
  uint in_EAX;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_28 [4];
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_2 == 0) {
    uVar2 = in_EAX & 0xffff0000;
  }
  else {
    if (param_3 == 0) {
      param_3 = 1;
      while (((uint)(int)param_3 <= (uint)(*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2)
             && (*(int *)(*(int *)(param_1 + 0x18) + -4 + param_3 * 4) != 0))) {
        param_3 = param_3 + 1;
      }
    }
    if (param_3 < 1) {
      uVar2 = (uint)(ushort)(param_3 >> 0xf) << 0x10;
    }
    else {
      while ((uint)(*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2) < (uint)(int)param_3)
      {
        local_28[2] = 0;
        FUN_0044845a(local_28 + 2);
        local_28[1] = 0;
        FUN_0042eab4(local_28 + 1);
      }
      if (*(int *)(*(int *)(param_1 + 0x18) + -4 + param_3 * 4) == 0) {
        *(int *)(*(int *)(param_1 + 0x18) + -4 + param_3 * 4) = param_2;
        *(undefined4 *)(*(int *)(param_1 + 0x24) + -4 + param_3 * 4) = 0xffff;
        *(short *)(param_2 + 0xf0) = param_3;
        if (param_4 == '\0') {
          *(undefined4 *)(param_2 + 0xe0) = *(undefined4 *)(param_1 + 0x30);
          *(int *)(param_1 + 0x30) = param_2;
          if (*(int *)(param_1 + 0x34) == 0) {
            *(int *)(param_1 + 0x34) = param_2;
          }
        }
        else if (*(int *)(param_1 + 0x34) == 0) {
          *(int *)(param_1 + 0x34) = param_2;
          *(int *)(param_1 + 0x30) = param_2;
        }
        else {
          *(int *)(*(int *)(param_1 + 0x34) + 0xe0) = param_2;
          *(int *)(param_1 + 0x34) = param_2;
        }
        local_c = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,
                               &cXPerson::RTTI_Type_Descriptor,0);
        if (local_c != 0) {
          FUN_0042eadb(&local_c);
        }
        local_10 = FUN_006359f2(param_2,0,&cXObject::RTTI_Type_Descriptor,
                                &cXPortal::RTTI_Type_Descriptor,0);
        if (local_10 != 0) {
          FUN_00457da4();
          sVar1 = FUN_004561a0(0xf);
          if (sVar1 != 0) {
            FUN_00448766(&local_10);
          }
        }
        local_28[3] = FUN_0045741b();
        FUN_004497ed(local_28,local_28 + 3);
        local_18 = local_28[0];
        if (local_28[0] != *(int *)(param_1 + 0x70)) {
          FUN_0044845a(&param_2);
        }
        *(undefined1 *)(param_1 + 0x44) = 1;
        local_14 = *(undefined4 *)(DAT_006e486c + 0x24);
        local_8 = (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2) * 0xf + 10000;
        iVar3 = FUN_00427162();
        iVar4 = FUN_00427162();
        DAT_006c4d60 = local_8 + iVar3 * iVar4 * 0xf;
        uVar2 = CONCAT22((short)((uint)DAT_006c4d60 >> 0x10),param_3);
      }
      else {
        uVar2 = (uint)(ushort)(param_3 >> 0xf) << 0x10;
      }
    }
  }
  return uVar2;
}

