
void * FUN_005c38c0(void *param_1,int param_2,float *param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  float10 fVar3;
  float10 fVar4;
  undefined4 uVar5;
  float local_180 [3];
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  float local_150;
  float local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  float local_13c;
  float local_138;
  undefined4 local_134;
  float local_130 [3];
  undefined4 local_124;
  undefined4 local_120;
  float local_11c;
  float local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  float local_f0;
  float local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined1 local_c0 [64];
  undefined1 local_80 [128];
  
  fVar3 = (float10)fcos((float10)*param_3);
  fVar4 = (float10)fsin((float10)*param_3);
  local_ec = (float)fVar4;
  if (param_2 == 0) {
    local_11c = -local_ec;
    local_118 = (float)fVar3;
    local_13c = (float)fVar3;
    local_100 = 0;
    local_fc = 0;
    local_f8 = 0;
    local_f4 = 0x3f800000;
    local_120 = 0;
    local_114 = 0;
    local_140 = 0;
    local_134 = 0;
    local_160 = 0x3f800000;
    local_15c = 0;
    local_158 = 0;
    local_154 = 0;
    local_138 = local_ec;
    FUN_005c47c0(&local_160);
    FUN_005c47c0(&local_140);
    FUN_005c47c0(&local_120);
    FUN_005c47c0(&local_100);
    _vector_constructor_iterator_(param_1,0x10,4,(_func_void_ptr_void_ptr *)&LAB_005c3c10);
    puVar2 = local_80;
  }
  else {
    if (param_2 != 1) {
      if (param_2 != 2) {
        FUN_005c36c0(&DAT_006fe6d0);
        return param_1;
      }
      local_150 = -local_ec;
      uVar5 = 0;
      local_14c = (float)fVar3;
      local_f0 = (float)fVar3;
      local_110 = 0;
      local_10c = 0;
      local_108 = 0;
      local_104 = 0x3f800000;
      local_e0 = 0;
      local_dc = 0;
      local_d8 = 0x3f800000;
      local_d4 = 0;
      local_148 = 0;
      local_144 = 0;
      local_e8 = 0;
      local_e4 = 0;
      uVar1 = FUN_00462e7a(&local_f0,&local_150,&local_e0,&local_110);
      FUN_005c3730(uVar1,uVar5);
      return param_1;
    }
    local_180[2] = (float)fVar3;
    local_130[0] = (float)fVar3;
    local_130[2] = -local_ec;
    local_170 = 0;
    local_16c = 0;
    local_168 = 0;
    local_164 = 0x3f800000;
    local_180[1] = 0.0;
    local_174 = 0;
    local_d0 = 0;
    local_cc = 0x3f800000;
    local_c8 = 0;
    local_c4 = 0;
    local_130[1] = 0.0;
    local_124 = 0;
    local_180[0] = local_ec;
    _vector_constructor_iterator_(local_c0,0x10,4,(_func_void_ptr_void_ptr *)&LAB_005c3c10);
    FUN_005c47c0(local_130);
    FUN_005c47c0(&local_d0);
    FUN_005c47c0(local_180);
    FUN_005c47c0(&local_170);
    _vector_constructor_iterator_(param_1,0x10,4,(_func_void_ptr_void_ptr *)&LAB_005c3c10);
    puVar2 = local_c0;
  }
  FUN_00462f2f(puVar2);
  *(undefined4 *)((int)param_1 + 0x40) = 0;
  return param_1;
}

