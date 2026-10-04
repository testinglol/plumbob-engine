
undefined4 __cdecl FUN_6001ab01(int param_1)

{
  undefined4 local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = FUN_600011b3(*(byte **)(param_1 + 0x18),1);
  local_8 = local_8 & 0xff;
  switch(local_8) {
  case 1:
  case 0x79:
    local_c = 1;
    break;
  case 3:
  case 0x7a:
    local_c = 4;
  }
  return local_c;
}

