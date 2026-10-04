
int __cdecl FUN_6001a196(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_c;
  
  switch(param_2) {
  case 1:
  case 0x79:
  default:
    local_c = 1;
    break;
  case 3:
  case 0x7a:
    local_c = 4;
  }
  iVar1 = param_1 * local_c + 7;
  return (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
}

