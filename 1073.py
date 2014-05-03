#!/usr/bin/env python
import re
if __name__ == '__main__':
    raw_num = raw_input()
    out_list = []
    sign = raw_num[0]
    
    # +1.23400E-03, -1.2E+10
    # 0.00123400, -12000000000
    expr = '([+-][1-9]\.[0-9]+)E([+-][0-9]+)'
    m = re.match(expr, raw_num)
    fract = m.group(1)
    fract = fract[1:]    
    fract = fract.replace('.', '')
    fract_len = len(fract)

    exp = m.group(2)
    exp_sign = exp[0]
    exp = exp[1:]
    exp_int = int(exp)

    if sign == '-':
        out_list.append(sign)    
    if exp_sign == '-':
        if exp_int > 0:
            out_list.append('0.' + '0' * (exp_int - 1))
        out_list.append(fract)
    else:
        if exp_int > fract_len:
            out_list.append(fract)
            out_list.append('0' * (exp_int - fract_len + 1))
        else:
            if exp_int > 0:
                if fract_len - exp_int > 1:
                    out_list.append(fract[0:exp_int + 1])
                    out_list.append('.')
                    out_list.append(fract[exp_int + 1:])
                else:
                    out_list.append(fract)
            else:
                out_list.append(fract)
    print ''.join(out_list)
