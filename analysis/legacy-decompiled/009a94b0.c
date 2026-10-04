
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __thiscall FUN_009a94b0(int *param_1,int *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 ****ppppuVar9;
  uint uVar10;
  float fVar11;
  undefined4 local_4c;
  int local_48;
  _Hash<std::_Uset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::_Uhash_compare<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,0>_>
  *local_44;
  int local_40;
  int *local_3c;
  int local_38;
  _Hash<std::_Uset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::_Uhash_compare<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,0>_>
  *local_34;
  undefined4 ***local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint local_20;
  uint local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00c4e665;
  local_10 = ExceptionList;
  local_14 = DAT_00dd0b80 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_3c = param_1;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 0x20))(0xffff,local_14);
  }
  cVar4 = (**(code **)(*param_2 + 0xc))();
  if (cVar4 == '\0') {
    uVar7 = 0;
  }
  else {
    if (param_1[1] == 0) {
      iVar2 = *param_1;
      local_44 = (_Hash<std::_Uset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::_Uhash_compare<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,0>_>
                  *)(iVar2 + 0xc);
      local_38 = **(int **)local_44;
      if (*(int *)(iVar2 + 0x10) == 0x15555555) {
                    /* WARNING: Subroutine does not return */
        FUN_00a0a80f("list too long");
      }
      local_8 = 0;
      local_40 = 0;
      piVar5 = (int *)FUN_00a30d62(0xc);
      local_8 = 0xffffffff;
      local_30 = (undefined4 ****)0x0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      piVar5[2] = (int)param_2;
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
      piVar3 = *(int **)(local_38 + 4);
      *piVar5 = local_38;
      piVar5[1] = (int)piVar3;
      *(int **)(local_38 + 4) = piVar5;
      *piVar3 = (int)piVar5;
      local_20 = 0;
      local_1c = 0;
      local_34 = (_Hash<std::_Uset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::_Uhash_compare<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,0>_>
                  *)(*local_3c + 0x1c);
      puVar6 = param_3;
      if (0xf < (uint)param_3[5]) {
        puVar6 = (undefined4 *)*param_3;
      }
      FUN_00413420(puVar6,param_3[4]);
      local_18 = param_2;
      local_8 = 1;
      uVar10 = 0x811c9dc5;
      ppppuVar9 = &local_30;
      if (0xf < local_1c) {
        ppppuVar9 = (undefined4 ****)local_30;
      }
      uVar8 = 0;
      if (local_20 != 0) {
        do {
          pbVar1 = (byte *)((int)ppppuVar9 + uVar8);
          uVar8 = uVar8 + 1;
          uVar10 = (*pbVar1 ^ uVar10) * 0x1000193;
        } while (uVar8 < local_20);
      }
      FUN_009a8850(&local_4c,&local_30,uVar10);
      if (local_48 == 0) {
        if (*(int *)(local_34 + 8) == 0x71c71c7) {
                    /* WARNING: Subroutine does not return */
          FUN_00a0a80f("unordered_map/set too long");
        }
        local_44 = local_34 + 4;
        local_8._0_1_ = 2;
        local_40 = 0;
        local_40 = FUN_00a30d62(0x24);
        local_38 = local_40 + 8;
        FUN_00437df0(&local_30);
        *(int **)(local_38 + 0x18) = local_18;
        local_8 = CONCAT31(local_8._1_3_,3);
        fVar11 = (float)((double)(*(int *)(local_34 + 8) + 1) +
                        (double)(&DAT_00c57f00)[-(*(int *)(local_34 + 8) + 1 >> 0x1f)]) /
                 (float)((double)*(int *)(local_34 + 0x1c) +
                        (double)(&DAT_00c57f00)[-(*(int *)(local_34 + 0x1c) >> 0x1f)]);
        if (*(float *)local_34 <= fVar11 && fVar11 != *(float *)local_34) {
          std::
          _Hash<std::_Uset_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::_Uhash_compare<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>,0>_>
          ::_Rehash_for_1(local_34);
          puVar6 = (undefined4 *)FUN_009a8850(&local_4c,local_38,uVar10);
          local_4c = *puVar6;
        }
        FUN_009aaee0(uVar10,local_4c,local_40);
      }
      local_8 = 0xffffffff;
      param_1 = local_3c;
      if (0xf < local_1c) {
        uVar10 = local_1c + 1;
        ppppuVar9 = (undefined4 ****)local_30;
        if (0xfff < uVar10) {
          ppppuVar9 = (undefined4 ****)local_30[-1];
          uVar10 = local_1c + 0x24;
          if (0x1f < (uint)((int)local_30 + (-4 - (int)ppppuVar9))) {
                    /* WARNING: Subroutine does not return */
            FUN_00a4104b();
          }
        }
        FUN_00a30993(ppppuVar9,uVar10);
        param_1 = local_3c;
      }
    }
    (**(code **)(*param_2 + 4))();
    if ((*(byte *)(param_1 + 4) & 0x10) != 0) {
      (**(code **)(*param_2 + 0x2c))(0x10,1);
    }
    uVar7 = 1;
  }
  ExceptionList = local_10;
  return uVar7;
}

