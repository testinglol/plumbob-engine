
void __thiscall FUN_004621ce(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[0x15] = 0;
  param_1[5] = 0xffffffff;
  param_1[6] = 0xffffffff;
  param_1[0x16] = 0;
  param_1[7] = 0xffffffff;
  param_1[8] = 0xffffffff;
  param_1[0x17] = 0;
  param_1[0x10] = 0;
  param_1[0x18] = 0;
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[0x19] = 0;
  param_1[0x11] = 0;
  param_1[0x1a] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x1b] = 0;
  param_1[0x14] = 0xfffffffe;
  param_1[4] = 1;
  param_1[0x1c] = 0;
  param_1[2] = param_3;
  param_1[0x12] = DAT_006e5490;
  uVar1 = FUN_006359f2(*(undefined4 *)(param_3 + 4),0,&cXObject::RTTI_Type_Descriptor,
                       &cXPerson::RTTI_Type_Descriptor,0);
  param_1[3] = uVar1;
  return;
}

